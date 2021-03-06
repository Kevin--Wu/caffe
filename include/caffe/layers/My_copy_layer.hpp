#ifndef CAFFE_MY_COPY_LAYER_HPP_
#define CAFFE_MY_COPY_LAYER_HPP_


#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

#include "caffe/layers/neuron_layer.hpp"

namespace caffe {

template <typename Dtype>
class MyCopyLayer : public NeuronLayer<Dtype> {
	
	public:
		explicit MyCopyLayer(const LayerParameter& param)
	      : NeuronLayer<Dtype>(param) {}
	    virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
	      const vector<Blob<Dtype>*>& top);

	    virtual inline const char* type() const { return "MyCopy"; }

	    //WHY ADD these?
	    virtual inline int ExactNumBottomBlobs() const { return 1; }

    protected:
		virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
		    const vector<Blob<Dtype>*>& top);
		void Backward_cpu(const vector<Blob<Dtype>*>& top,
		  const vector<bool>& propagate_down,
	      const vector<Blob<Dtype>*>& bottom);

		Dtype change_scale;

};

}


#endif