#include <iostream>

using namespace std ;

bool isSafe(int n, bool sol[][10], int r , int c, bool rc[], bool cc[], bool dc[] ) {
    
    if( dc[(r-c)+n-1]==0 ) {
        cout << "Left diagonal filled.\n" ;
        return false ;
    }
    if( dc[(r+c)+n-1]==0 ) {
        cout << "Left diagonal filled.\n" ;
        return false ;
    }
    if( rc[r]==0 ) {
        cout << "Left diagonal filled.\n" ;
        return false ;
    }
    if( cc[c]==0 ) {
        cout << "Left diagonal filled.\n" ;
        return false ;
    }
    
    return true ;

}

bool placeQueen( int n, bool sol[][10], int i, bool rc[], bool cc[], bool dc[] ) {

    if ( i==n )
        return true;

                    
    for ( auto k = 0 ; k < n ; ++k ) {

        if ( isSafe(n,sol,i,k,rc,cc,dc) ) {
            cout << "Placing one at " << i << " , " << k <<'\n';
            sol[i][k] = 1 ;
            dc[i+k+n-1] = 0 ;
            dc[i-k+n-1] = 0 ;
            rc[i] = 0;
            cc[k] = 0;
            if ( placeQueen( n, sol, i+1, rc, cc, dc ) ) 
                return true ;
            cout << "Didnt work\n\n\n";
            dc[i+k+n-1] = 1 ;
            dc[i-k+n-1] = 1 ;
            rc[i] = 1;
            cc[k] = 1;
            sol[i][k] = 0 ;
        }

    }

    return false ;

    
}

int main() {

    int n;
    cin >> n ;
    bool sol[10][10]={0}, dc[30], cc[10], rc[10] ;
    
    memset(dc,true,sizeof(dc)) ;
    memset(cc,true,sizeof(cc)) ;
    memset(rc,true,sizeof(rc)) ;

    placeQueen( n, sol, 0, rc, cc, dc ) ;

    for ( auto i = 0 ; i < n ; ++i ) {
        for ( auto j = 0 ; j < n ; ++j )
            cout << sol[i][j] << ' ' ;
        cout << '\n' ;
    }

}
 
