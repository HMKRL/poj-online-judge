#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
	int l, r;
	Node *left, *right;
	long long int sum;
	long long int inc;
};

class SegTree {
public:
	Node* Tree;
	int* num;
	long long int ans_sum;
	int NodeCnt;

	SegTree() {
		Tree = new Node[200200];
		num = new int[100100];
		ans_sum = 0;
		NodeCnt = 0;
	}
	
	void set_num(int n) {
		for(int i = 1; i <= n; ++i){
			scanf("%d", &num[i]);
		}
	}
	
	long long int get_sum(int l, int r) {
		ans_sum = 0;
		query(Tree, l, r);
		return ans_sum;
	}
	
	void build(Node *rt, int l, int r){
		rt->l = l;
		rt->r = r;
		if(l == r){
			rt->inc = 0;
			rt->sum = num[l];
			return;
		};
		rt->left = Tree + (++NodeCnt);
		rt->right = Tree + (++NodeCnt);
		
		int m = (l + r) >> 1;
		build(rt->left, l, m);
		build(rt->right, m + 1, r);
		rt->sum = rt->left->sum + rt->right->sum;
	}
	
	void pushdown(Node *rt){
		if(rt->inc){
			rt->left->inc += rt->inc;
			rt->right->inc += rt->inc;
			rt->left->sum += (((rt->left->r - rt->left->l) + 1) * rt->inc);
			rt->right->sum += (((rt->right->r - rt->right->l) + 1) * rt->inc);
			rt->inc = 0;
		}
	}
	
	void query(Node *rt, int l, int r){
		if(rt->l == l && rt->r == r){
			ans_sum += rt->sum;
			return;
		}
		pushdown(rt);
		int m = (rt->l + rt->r) >> 1;
		if(r <= m){
			query(rt->left, l, r);
		}else if(l > m){
			query(rt->right, l, r);
		}else{
			query(rt->left, l, m);
			query(rt->right, m + 1, r);
		}
	}
	
	void update(Node *rt, int l, int r, long long inc){
		if(rt->l == l && rt->r == r){
			rt->inc += inc;
			rt->sum += (((rt->r - rt->l) + 1) * inc);
			return ;
		}
		pushdown(rt);
		int m = (rt->l + rt->r) >> 1;
		if(r <= m){
			update(rt->left, l, r, inc);
		}else if(l > m){
			update(rt->right, l, r, inc);
		}else{
			update(rt->left, l , m, inc);
			update(rt->right, m + 1, r, inc);
		}
		rt->sum = rt->left->sum + rt->right->sum;
	}
};


int main() {
	SegTree ST;
	int a, b, l, r;
	long long int add;
	char c;
	
	while(scanf("%d%d", &a, &b) != EOF){
		ST.set_num(a);
		ST.build(ST.Tree, 1, a);
		for(int i = 0; i < b; ++i){
			getchar();
			scanf("%c", &c);
			scanf("%d%d", &l, &r);
			if(c == 'Q'){
				printf("%lld\n", ST.get_sum(l, r));
			}
			else{
				scanf("%lld", &add);
				ST.update(ST.Tree, l, r, add);
			}
		}
	}
	return 0;
}
