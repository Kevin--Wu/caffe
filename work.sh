#!/bin/bash

sh mywork/hmdb51/create_imagenet1.sh > done.txt &
sh mywork/hmdb51/create_imagenet2.sh > done.txt &
sh mywork/hmdb51/create_imagenet3.sh > done.txt &

