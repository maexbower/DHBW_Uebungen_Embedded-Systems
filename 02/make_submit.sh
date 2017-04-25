#!/bin/bash
if [[ ( -d ./bin ) && ( -d ./src ) && ( -d ./include ) ]]
  then
    make start
  fi
