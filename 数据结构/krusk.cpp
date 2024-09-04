#include<stdio.h>
#define MAXSIZE 100
#define MAXINT 65535

typedef struct
{
    char vexs[ MAXSIZE ] ;
    int arcs[ MAXSIZE ][ MAXSIZE ] ;
    int VertexNum , EdgeNum ;
}MGraph ;

typedef struct EdgeNode
{
    int begin ;
    int end ;
    int weigth ;
}EdgeAdjlist[ MAXSIZE ] , EdgeNode ;

void CreateMGraph( MGraph *G ) ;
int Locate( MGraph G , char ch ) ;
void TransEdge( EdgeAdjlist edge , MGraph G ) ;
void MiniSpanTree_Kruskal( MGraph G ) ;

int find( int x ) ;
int parent[ MAXSIZE ] ;

int main( void )
{
    MGraph G ;
    CreateMGraph( &G ) ;
    MiniSpanTree_Kruskal( G ) ;


    return 0 ;
}

int Locate( MGraph G , char ch )//找到结点在顶点数组中的下标
{
    int i ;
    for( i = 0 ; i < G.EdgeNum ; i++ )
        if( ch == G.vexs[ i ] )
            break ;
    return i ;
}

void CreateMGraph( MGraph *G )//创建邻接矩阵
{
    int i , weight , pos1 , pos2 ;
    char x , y ;
    printf( "请输入图中结点的个数：" ) ;
    scanf( "%d" , &G->VertexNum ) ;
    getchar() ;

    for( i = 0 ; i < G->VertexNum ; i++ )
    {
        printf( "请输入第%d个结点的信息：" , i + 1 ) ;
        scanf( "%c" , &G->vexs[ i ] ) ;
        getchar() ;
    }

    printf( "请输入图的边的条数：" ) ;
    scanf( "%d" , &G->EdgeNum ) ;
    getchar() ;

    for( i = 0 ; i< G->EdgeNum ; i++ )
    {
        printf( "请输入第%d条边的两个结点信息，和边的权值：" , i+ 1 ) ;
        scanf( "%c %c %d" , &x , &y , &weight ) ;
        getchar() ;

        pos1 = Locate( *G , x ) ;
        pos2 = Locate( *G , y ) ;

        G->arcs[ pos1 ][ pos2 ] = weight ;
        G->arcs[ pos2 ][ pos1 ] = weight ;
    }
}

void TransEdge( EdgeAdjlist edge , MGraph G )
{
    int i , j  , k = 0  ;
    EdgeNode t ;
    for( i = 0 ; i < G.VertexNum ; i++ )
        for(  j = i + 1 ; j < G.VertexNum ; j++ )
            if( G.arcs[ i ][ j ] > 0 && G.arcs[ i ][ j ] < MAXINT )
            {
                edge[ k ].begin = i ;
                edge[ k ].end = j ;
                edge[ k ].weigth = G.arcs[ i ][ j ] ;
                k++ ;
            }

    for( i = 0 ; i < G.EdgeNum - 1 ; i++ )
        for( j = 0 ; j < G.EdgeNum - i - 1 ; j++ )
            if( edge[ j ].weigth > edge[ j + 1 ].weigth )
            {
                t = edge[ j ] ;
                edge[ j ] = edge[ j+ 1 ] ;
                edge[ j+ 1 ] = t ;
            }
}

int find( int x )//找结点所在集合的根节点
{
    if( parent[ x ] > 0 )
        x = find( parent[ x ] ) ;
    return x ;
}

void MiniSpanTree_Kruskal( MGraph G )
{
    int i ,  n , m ;
    EdgeAdjlist edge ;

    TransEdge(  edge ,  G ) ;

    for( i = 0 ; i < G.VertexNum ; i++ )
        parent[ i ] = 0 ;

    for( i = 0 ; i < G.EdgeNum ; i++ )
    {
        n = find( edge[ i ].begin ) ;
        m = find( edge[ i ].end ) ;

        if( n != m )
        {
            parent[ n ] = m ;
            printf( "%c ===== %c , %d\n" , G.vexs[ edge[ i ].begin ] , G.vexs[ edge[ i ].end ] , edge[ i ].weigth ) ;
        }
    }
}
