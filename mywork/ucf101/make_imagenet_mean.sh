#!/usr/bin/env sh
# Compute the mean image from the imagenet training lmdb
# N.B. this is available in data/ilsvrc12

EXAMPLE=~/whx/dataset/ucf101/jpgoutput/split1
DATA=~/whx/caffe/mywork/ucf101
TOOLS=build/tools

$TOOLS/compute_image_mean $EXAMPLE/ucf101_train_lmdb \
  $DATA/imagenet_mean.binaryproto

echo "Done."
