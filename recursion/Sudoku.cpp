#include <iostream>
#include <vector>
using namespace std ;

bool canPlace( int arr[9][9], int n, int i, int j, int val ) {

    //cout << " U can place " << val << " at " << i << " and " << j << ".\n" ;
    for ( int x = 0 ; x < 9 ; ++x ) 
        if ( arr[i][x] == val || arr[x][j] == val ) 
            return false ;
    
    int cx = i/3 ;
    cx *= 3 ;
    int cy = j/3 ;
    cy *= 3 ;
    
    for ( int x = cx ; x < cx+3 ; ++x ) 
        for ( int y = cy ; y < cy+3 ; ++y ) 
            if ( arr[x][y] == val )
                return false ;
    return true ;
    
}
bool solveSudoku( int arr[9][9] , int n, int i, int j ) {

    if ( i == n ){
        cout << "\n\nSolution:\n" ;
        for ( int i = 0 ; i < 9 ; ++i ) {
            for ( int  j = 0 ; j < 9 ; ++j )
                cout << arr[i][j] << ' ';
            cout << "\n" ;
        }
        return true ;
    }
    
    if ( arr[i][j] == 0 ) {
        for ( int x = 1 ; x < 10 ; ++x ) 
            if ( canPlace(arr,n,i,j,x) ) {
                arr[i][j] = x ;
                //cout << "\nUsing " << x << " on " << i << " and " << j << ".\n" ;
                if ( solveSudoku( arr, n, i + (j+1)/n, (j+1)%n ) ) 
                    return true ;
                arr[i][j] = 0 ;
            }
    }
    else {
        return solveSudoku( arr, n, i + (j+1)/n, (j+1)%n ) ;
    }
    return false ;

}

int main() {

//    freopen("input.txt","r",stdin) ;
//    freopen("output.txt","w",stdout) ;

    int arr[9][9] ;

    for ( int i = 0 ; i < 9 ; ++i )
        for ( int  j = 0 ; j < 9 ; ++j )
            cin >> arr[i][j] ;
    
    if ( solveSudoku(arr,9,0,0) )
        cout << "\n\nSOLVED!!" ; 
    else 
        cout << "\n\nNoT SOLVED!!" ; ;

}
