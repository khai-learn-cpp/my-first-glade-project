#! /usr/bin/env sh
[ -n "$CXX" ] || (
  echo 'Missing environment variable CXX' >&2
  echo 'CXX variable should points to a GCC-like C++ compiler' >&2
  exit 1
) && (
  (
    libversion=$(pkg-config --modversion gtkmm-3.0) || exit $?
    echo Using GTKmm version $libversion
    libflags=$(pkg-config gtkmm-3.0 --cflags --libs) || exit $?
    echo 'Building...'
    $CXX -std=c++14 -Wall -Wextra -o main main.cpp $libflags
  ) && (
    echo 'done.'
  ) || (
    code=$?
    echo 'failed.'
    exit $code
  )
)
