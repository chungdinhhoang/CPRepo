#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

/**
 * Description: Policy-based data structures that supports normal set operation and
 *    * find_by_order(k)  returns iterator to kth element starting from 0;
 *    * order_of_key(k)   returns count of elements strictly [smaller] than k;
 * Caution: 
 *    * do not define int long long before below declaration
 */

template <class T, class cmp = std::less<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag,tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
