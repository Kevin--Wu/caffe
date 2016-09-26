#include <vector>
#include <algorithm>

#include "caffe/layers/My_copy_layer.hpp"

namespace caffe {

	template <typename Dtype>
	void MyCopyLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
	      const vector<Blob<Dtype>*>& top) {

		NeuronLayer<Dtype>::LayerSetUp(bottom, top);
		top[0]->Reshape(bottom[0]->shape());

	}

	template <typename Dtype>
	void MyCopyLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
	      const vector<Blob<Dtype>*>& top){
		const int count=top[0]->count();
		caffe_copy(count,bottom[0]->cpu_data(),top[0]->mutable_cpu_data());
	}

	template <typename Dtype>
	void MyCopyLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& bottom,
	      const vector<Blob<Dtype>*>& top){
		const int count=top[0]->count();
		const Dtype* top_diff = top[0]->cpu_diff();
		change_scale=this->layer_param_.mycopy_param().change_scale();

		if(propagate_down[0]){
			Dtype* bottom_diff=bottom[0]->mutable_cpu_diff();
			caffe_cpu_axpby(count,change_scale,top_diff,Dtype(0),bottom_diff)
		}
	}

#ifdef CPU_ONLY
	STUB_GPU(MyCopyLayer);
#endif

INSTANTIATE_CLASS(MyCopyLayer);
REGISTER_LAYER_CLASS(MyCopy);

}// namespace caffe