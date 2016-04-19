namespace CoreLib { namespace System {
	struct IntPtr;
	struct UIntPtr;
}}

extern CoreLib::System::IntPtr _interlocked_exchange(CoreLib::System::IntPtr volatile* location1, CoreLib::System::IntPtr value);
extern CoreLib::System::IntPtr _interlocked_compare_exchange(CoreLib::System::IntPtr volatile* location1, CoreLib::System::IntPtr value, CoreLib::System::IntPtr comparand);

extern CoreLib::System::UIntPtr _interlocked_exchange(CoreLib::System::UIntPtr volatile* location1, CoreLib::System::UIntPtr value);
extern CoreLib::System::UIntPtr _interlocked_compare_exchange(CoreLib::System::UIntPtr volatile* location1, CoreLib::System::UIntPtr value, CoreLib::System::UIntPtr comparand);

#ifdef _MSC_VER
#include <intrin.h>

// InterlockedExchange
template < typename T >
inline typename std::enable_if<sizeof(T) == 1 && !std::is_pointer<T>::value, T>::type _interlocked_exchange(T volatile* location1, T value)
{
	return (T) _InterlockedExchange8((int8_t volatile*)location1, (int8_t)value);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 2 && !std::is_pointer<T>::value, T>::type _interlocked_exchange(T volatile* location1, T value)
{
	return (T) _InterlockedExchange16((int16_t volatile*)location1, (int16_t)value);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 4 && !std::is_pointer<T>::value, T>::type _interlocked_exchange(T volatile* location1, T value)
{
	return (T) _InterlockedExchange((int32_t volatile*)location1, (int32_t)value);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 8 && !std::is_pointer<T>::value, T>::type _interlocked_exchange(T volatile* location1, T value)
{
	return (T) _InterlockedExchange64((int64_t volatile*)location1, (int64_t)value);
}

template < typename T >
inline typename std::enable_if<std::is_pointer<T>::value, T>::type _interlocked_exchange(T volatile* location1, T value)
{
	return (T) _InterlockedExchangePointer((void* volatile*)location1, (void*)value);
}

// InterlockedCompareExchange
template < typename T >
inline typename std::enable_if<sizeof(T) == 1 && !std::is_pointer<T>::value, T>::type _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return (T) _InterlockedCompareExchange8((int8_t volatile*)location1, (int8_t)value, (int8_t)comparand);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 2 && !std::is_pointer<T>::value, T>::type _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return (T) _InterlockedCompareExchange16((int16_t volatile*)location1, (int16_t)value, (int16_t)comparand);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 4 && !std::is_pointer<T>::value, T>::type _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return (T) _InterlockedCompareExchange((int32_t volatile*)location1, (int32_t)value, (int32_t)comparand);
}

template < typename T >
inline typename std::enable_if<sizeof(T) == 8 && !std::is_pointer<T>::value, T>::type _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return (T) _InterlockedCompareExchange64((int64_t volatile*)location1, (int64_t)value, (int64_t)comparand);
}

template < typename T >
inline typename std::enable_if<std::is_pointer<T>::value, T>::type _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return (T) _InterlockedCompareExchangePointer((void* volatile*)location1, (void*)value, (void*)comparand);
}

#else // _MSC_VER

template < typename T >
inline T _interlocked_exchange(T volatile* location1, T value)
{
	__sync_synchronize();
	return __sync_lock_test_and_set(location1, (T)value);
}

template < typename T >
inline T _interlocked_compare_exchange(T volatile* location1, T value, T comparand)
{
	return __sync_val_compare_and_swap(location1, comparand, value);
}

#endif 