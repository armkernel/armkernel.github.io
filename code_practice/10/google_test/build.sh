#!/bin/sh

g++ $1 -I. -lgtest -L. -pthread -std=c++1z
