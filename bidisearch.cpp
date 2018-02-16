#include<bits/stdc++.h>
using namespace std;
class Graph
{
	public:
	int v;
	vector<int> *adj;
	vector<int> *wgt;
	Graph(int v)
	{
		this->v=v;
		adj=new vector<int>[v];
		wgt=new vector<int>[v];
	}
	void addEdge(int v,int w,int wt)
	{
		adj[v].push_back(w);
		wgt[v].push_back(wt);
	}
	int visitedIntersect(bool *s_visit,bool *t_visit)
	{
		for(int j=v-1;j>=0;j--)
		{
			if(s_visit[j]&&s_visit[j]==t_visit[j])
				return j;
		}
		return -1;
	}
	void bfs(list<int> *queue1,bool *visited,int *prev)
	{
		int curr=queue1->front();
		queue1->pop_front();
		for(auto i=adj[curr].begin();i!=adj[curr].end();i++)
		{
			if(!visited[*i])
			{
				prev[*i]=curr;
				visited[*i]=true;
				queue1->push_back(*i);
			}
		}
	}
	void printPath(int s,int t,int *s_prev,int *t_prev,int m_pt)
	{
		int p,q,pos,pathlength=0,cnt=2;
		int *prev=s_prev;
		vector<int> result;
		while(cnt--)
		{
			p=m_pt;
			while(p!=-1)
			{
				result.push_back(p);
				q=prev[p];
				if(q!=-1)
					pathlength++;
				p=q;
			}
			prev=t_prev;
		}
		auto i=result.begin()+1;
		cout<<*i;
		i++;
		for(;i!=result.end();i++)
			cout<<"->"<<*i;
		cout<<"\n";
	}
	void BDS(int s,int t)
	{
		bool *s_visit=new bool[v];
		bool *t_visit=new bool[v];
		int *s_prev=new int[v];
		int *t_prev=new int[v];
		int meet_pt=-1;
		for(int i=0;i<v;i++)
		{
			s_visit[i]=false;
			t_visit[i]=false;
		}
		list<int> s_queue,t_queue;
		s_visit[s]=true;
		s_prev[s]=-1;
		s_queue.push_back(s);
		t_visit[t]=true;
		t_prev[t]=-1;
		t_queue.push_back(t);
		while(!s_queue.empty()&&!t_queue.empty())
		{
			bfs(&s_queue,s_visit,s_prev);
			bfs(&t_queue,t_visit,t_prev);
			meet_pt=visitedIntersect(s_visit,t_visit);
			if(meet_pt!=-1)
			{
				printPath(s,t,s_prev,t_prev,meet_pt);
				return;
			}
		}
	}
	void printGraph()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<" ";
			for(auto j=adj[i].begin();j!=adj[i].end();j++)
				cout<<*j<<" ";
			cout<<"\n";
		}
	}
};
int main()
{
	cout<<"Enter No. of vertices and edges\n";
	int v,e,a,b,w,source,target;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		g.addEdge(a-1,b-1,1);
		g.addEdge(b-1,a-1,1);
	}
	cout<<"Enter Source and Target\n";
	cin>>source>>target;
	//g.printGraph();
    g.BDS(source-1,target-1);
	
}