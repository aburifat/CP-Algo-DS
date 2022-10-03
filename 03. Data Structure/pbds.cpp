#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
    ordered_set oss;

    //insert value
    oss.insert(b);

    //get the size
    ll len=oss.size();

    //get index of value
    ll pos=oss.order_of_key(val);

    //get value of the index
    ll val=*oss.find_by_order(pos);

    //erase value by position
    oss.erase(oss.find_by_order(pos));

    //find and delete value
    ll pos=oss.order_of_key(a);
	ll val=*oss.find_by_order(pos);
	if(a==val)oss.erase(oss.find_by_order(pos));

    return 0;
}
