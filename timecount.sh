#!bin/bash
start_time=`date +%s`
#sh examples/mnist/train_lenet.sh
sleep 2
end_time=`date +%s`
echo
echo
echo '==============================================='
echo "the total time cost is `expr $end_time - $start_time` s"
