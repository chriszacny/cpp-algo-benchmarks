import sys
import os
import timeit

LOWER_BOUND = 1000000
UPPER_BOUND = 9999999


def bit_map_test():
    bit_map = {}
    linesep = os.linesep
    with open(sys.argv[1], 'r') as r_hdl:
        for line in r_hdl:
            bit_map[int(line)] = True
    with open('%s.bitmapsort' % sys.argv[2], 'w') as w_hdl:
        for i in range(LOWER_BOUND, UPPER_BOUND + 1):
            if i in bit_map:
                w_hdl.write(str(i) + linesep)


def python_sort_test():
    unsorted_list = []
    with open(sys.argv[1], 'r') as r_hdl:
        for line in r_hdl:
            unsorted_list.append(line)
    unsorted_list.sort()
    with open('%s.pysort' % sys.argv[2], 'w') as w_hdl:
        for value in unsorted_list:
            w_hdl.write(value)


def performance_test():
    my_list = []
    for i in range(0, 1000000):
        my_list.append(False)


def main():
    bit_map_test()
    #python_sort_test()


if __name__ == '__main__':
    print(timeit.timeit('bit_map_test()', setup="from __main__ import bit_map_test", number=3))
    #print(timeit.timeit('performance_test()', setup="from __main__ import performance_test", number=3))
    print(timeit.timeit('python_sort_test()', setup="from __main__ import python_sort_test", number=3))
    #main()
