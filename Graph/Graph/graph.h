/*------邻接矩阵表示法------*/
typedef char VertexType;//顶点类型
typedef int EdgeType;//边上权值类型
#define MAXSIZE 10
VertexType Vertex[MAXSIZE];//定义
EdgeType Matrix[MAXSIZE][MAXSIZE];
void CreateGraphByMatrix(int *pv);
