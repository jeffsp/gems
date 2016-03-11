#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    foo
    ~~~

    test script

    jsp Tue Jan 12 15:20:50 CST 2016
"""

from __future__ import print_function
import argparse
import sys


# pylint: disable=no-member
# pylint: disable=line-too-long
# pylint: disable=expression-not-assigned


def main():
    """
    Main function
    """
    parser = argparse.ArgumentParser(description='Test script')
    parser.add_argument("-v", "--verbose", dest="verbose", help="verbose flag", action="store_true")
    parser.add_argument("-s", "--success", dest="success", help="success flag", action="store_true")
    parser.add_argument("-f", "--fail", dest="fail", help="fail flag", action="store_true")

    args = parser.parse_args()

    if args.verbose:
        print('verbose', args.verbose)
        print('success', args.success)
        print('fail', args.fail)
    if args.fail:
        sys.exit(-1)
    else:
        sys.exit(0)

    return args


if __name__ == '__main__':

    main()
