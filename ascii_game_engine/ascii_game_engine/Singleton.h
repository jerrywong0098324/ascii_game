// template class for any singleton design pattern
template <typename T>
class Singleton
{
public:
	static T *GetInstance()
	{
		static T *instance;
		if (instance)
			instance = new T;
		return instance;
	}

	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

protected:
	Singleton() {}
	~Singleton() {}
};