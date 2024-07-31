#include <iostream>
#include <optional>
#include <memory>
#include <mutex>



template <class T>
class circular_buffer {
public:
	explicit circular_buffer(size_t size) :
		buf_(std::unique_ptr<T[]>(new T[size])),
		max_size_(size)
	{}
	
	void reset() {
		std::lock_guard<std::mutex> lock(mutex_);
		head_ = tail_;
		full_ = false;
	}
	
	bool is_empty() const {
		return (!full_) && (head_ == tail_);
	}
	
	bool is_full() const {
		return full_;
	}
	
	size_t capacity() const {
		return max_size_;
	}
	
	size_t size() const {
		size_t buff_size;
		if (head_ > tail_) {
			buff_size = head_ - tail_;
		} else {
			buff_size = head_ - tail_ + max_size_;
		}
		
		return buff_size;
	}
	
	void put(T data) {
		std::lock_guard<std::mutex> lock(mutex_);
		
		buf_[head_] = data;
		
		if (is_full()) {
			tail_ = (tail_ + 1) % max_size_;
		}
		
		head_ = (head_ + 1) % max_size_;
		
		full_ = head_ == tail_;
	}
	
	std::optional<T> get() {
	
		std::optional<T> item;
		std::lock_guard<std::mutex> lock(mutex_);
		
		if (is_empty()) return std::nullopt;
		
		item = buf_[tail_];
		
		full_ = false;
		
		tail_ = (tail_ + 1) % max_size_;
		
		return item;
	}

private:
	std::mutex mutex_;
	std::unique_ptr<T[]> buf_;
	size_t head_ = 0;
	size_t tail_= 0;
	const size_t max_size_;
	bool full_ = 0;
};


int main()
{
   circular_buffer<uint32_t> circle(10);
   
   uint32_t x = 100;
   
   circle.put(x);
   
   auto const item = circle.get();
   
   if (item.has_value()) {
      std::cout << "Data in circ_buff: " << item.value() << std::endl;
   }
   
    return 0;
}



