#ifndef H6F1EF34F_B147_4BB3_8FE9_95D9ACF6C640
#define H6F1EF34F_B147_4BB3_8FE9_95D9ACF6C640


#if __cplusplus >= 201402L
#define SM_DEPRECATED(msg) [[deprecated(msg)]]
#define SM_DEPRECATION_SUPPORTED
#elif defined(__GNUC__)
#define SM_DEPRECATED(msg) __attribute__((deprecated))
#define SM_DEPRECATION_SUPPORTED
#elif defined(_MSC_VER)
#define SM_DEPRECATED(msg) __declspec(deprecated)
#define SM_DEPRECATION_SUPPORTED
#else
#define SM_DEPRECATED(msg)
#endif

#endif /* H6F1EF34F_B147_4BB3_8FE9_95D9ACF6C640 */
