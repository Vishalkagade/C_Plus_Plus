#!/usr/bin/env bats
# @file      test_task_1.sh
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2020 Ignacio Vizzo, all rights reserved


@test "[task_1] Check bin/task_1 existance" {
  run test -e task1/bin/task_1
  (( status == 0 ))
}

@test "[task_1] Check error handling" {
  run eval "echo | task1/bin/task_1 > /dev/null"
  (( status == 1 ))
  [ "${lines[0]}" = "Error encountered, exiting..." ]
}

@test "[task_1] Check random number betwwen [0-99]" {
  number=$(echo | .task1/bin/task_1 2> /dev/null |  grep -o -E '[0-9]+' |tail -1)

  (( status == 0 ))
  [ $number -ge 0 ]
  [ $number -le 99 ]
}

@test "[task_1] Check randomness" {
  results_1=$(echo | .task1/bin/task_1 2> /dev/null |  grep -o -E '[0-9]+' |tail -1)
  results_2=$(echo | .task1/bin/task_1 2> /dev/null |  grep -o -E '[0-9]+' |tail -1)

  (( status == 0 ))
  [ $results_1 -ne $results_2 ]
}
