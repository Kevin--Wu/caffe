#!/bin/bash

rm -fr ~/whx/dataset/hmdb/hmdb51_jpg_split/*
sh mywork/ucf101/create_imagenet1.sh > done.txt
sh mywork/ucf101/make_imagenet_mean.sh > done2.txt

