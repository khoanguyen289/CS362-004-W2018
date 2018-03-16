''' 
 Khoa Nguyen
 CS 362
 03-11-2018

This is an implementation of the Tarantula debugging method. It specifically calls the 
randomtestcard1 function to test dominion.c implementation if the Smithy card is correctly
placed into the played pile after being played. That said, this Tarantula implementation
can easily be modified to be used for other tests. After running, it will print to console
a color-coded version of the source file dominion.c. The colors are based on suspiciousness
level of each line of the code as described below:

-Black: low suspiciousness
-Magenta: moderate suspiciousness
-Red: high suspiciousness

CREDIT: https://github.com/cs362sp15/projects/blob/master/hubbarsp/dominion/tarantula.py'

'''

from __future__ import division

import sys
import os
import subprocess

def print_red(msg):
    print '\033[91m' + msg + '\033[0m'

def print_green(msg):
    print '\033[92m' + msg + '\033[0m'

def print_magenta(msg):
    print '\033[95m' + msg + '\033[0m'

def count_lines(fname):
    return len(open(fname, 'r').readlines())

def count_digits(n):
    count = 0
    while n != 0:
        count += 1
        n = n // 10
    return count

def get_result(msg):
    return msg == 1

def suspiciousness(passed, failed, total_passed, total_failed):
    if total_failed == 0:
      return 0
    if total_passed == 0:
      return 1
    
    numerator = failed / total_failed
    denominator = passed / total_passed + numerator
    return numerator / denominator

def main():
    source_file = 'dominion.c'

    # define variables used to compute suspiciousness of coverage unit
    count = count_lines(source_file)
    passed = [0 for i in range(count + 1)]
    failed = [0 for i in range(count + 1)]
    total_passed = 0
    total_failed = 0

    # run the random test 50 times
    for i in range(1, 50):
      # compile and execute unit test
      subprocess.call(['make', 'clean'])
      subprocess.call(['make', 'randomtestcard1'])
      try:
          tmp = subprocess.check_output(['./randomtestcard1'], stderr=subprocess.STDOUT)
      except subprocess.CalledProcessError as e:
          tmp = e.returncode
      # record test result
      result = get_result(tmp)
      
      if (result):
          # test passed
          total_passed += 1
      else:
          # test failed
          total_failed += 1
      # execute gcov on source file and record results
      subprocess.call(['gcov', source_file])
      for line in open(source_file + '.gcov', 'r').readlines():
          tmp = line.split(':')
          num = tmp[0].lstrip()
          i = int(tmp[1])
          if num.startswith('-') or num.startswith('#') or num.startswith('='):
              # line not executed
              continue
          elif result:
              # line executed by passing test
              passed[i] += 1
          else:
              # line executed by failing test
              failed[i] += 1
  # print tarantula results
    width = count_digits(count)
    i = 1
    for line in open(source_file, 'r').readlines():
        msg = str(i).rjust(width) + ':' + line[:-1]
        if passed[i] > 0 or failed[i] > 0:
            # some test executed this line
            tmp = suspiciousness(passed[i], failed[i], total_passed, total_failed)
            if tmp == 0:
                # line only executed by passing tests; not suspicious
                print_green(msg)
            elif tmp <= 0.5:
                # somewhat suspicious
                print_magenta(msg)
            else:
                # very suspicious
                print_red(msg)
        else:
          # no test executed this line
          print msg
        i += 1

# call main function if running as program
if __name__ == '__main__':
    main()