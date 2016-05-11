#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
	int l, r;
	Node *left, *right;
	int mass_num;
	int r_con;
	int l_con;
};

class SegTree {
public:
	Node* Tree;
	int* num;
	int NodeCnt;

	SegTree() {
		Tree = new Node[200200];
		num = new int[100100];
		NodeCnt = 0;
	}
	
	void set_num(int n) {
		for(int i = 1; i <= n; ++i){
			scanf("%d", &num[i]);
		}
	}
	
	void build(Node *rt, int l, int r){
		rt->l = l;
		rt->r = r;
		if(l == r){
			rt->mass_num = 1;
			rt->r_con = 1;
			rt->l_con = 1;
			return;
		};
		rt->left = Tree + (++NodeCnt);
		rt->right = Tree + (++NodeCnt);
		
		int m = (l + r) >> 1;
		build(rt->left, l, m);
		build(rt->right, m + 1, r);
		int new_max = rt->left->mass_num > rt->right->mass_num ? rt->left->mass_num : rt->right->mass_num;
		if(num[m] == num[m + 1]) {
			if((rt->left->r_con + rt->right->l_con) > new_max) {
				rt->mass_num = new_max > rt->left->r_con + rt->right->l_con ? new_max : rt->left->r_con + rt->right->l_con;
			}
		}
		else {
			rt->mass_num = new_max;
		}
		rt->r_con = rt->right->r_con;
		rt->l_con = rt->left->l_con;
		if(num[m] == num[m + 1]) {
			if(m - l + 1 == rt->left->r_con) rt->l_con += rt->right->l_con;
			if(r - m == rt->right->l_con) rt->r_con += rt->left->r_con;
		}
	}
	
	int query(Node *rt, int l, int r) {
		int cross, Max;
		if(rt->l == l && rt->r == r) {
			return rt->mass_num;
		}
		int m = (rt->l + rt->r) >> 1;
		if(r <= m) {
			Max = query(rt->left, l, r);
		}
		else if(l > m) {
			Max =  query(rt->right, l, r);
		}
		else {
			int a, b;
			a = query(rt->left, l, m);
			b = query(rt->right, m + 1, r);
			Max = a > b ? a : b;
		}
		if(num[m] == num[m + 1]) {
			cross = min((m - l + 1), rt->left->r_con) + min((r - m), rt->right->l_con);
			Max = Max > cross ? Max : cross;
		}
		return Max;
	}
};


int main() {
	SegTree* ST;
	int a, b, l, r;
	
	while(1){
		ST = new SegTree;
		scanf("%d", &a);
		if(a == 0) break;
		scanf("%d", &b);
		ST->set_num(a);
		ST->build(ST->Tree, 1, a);
		for(int i = 0; i < b; ++i){
			scanf("%d%d", &l, &r);
			printf("%d\n", ST->query(ST->Tree, l, r));
		}
		delete ST;
	}
	return 0;
}
