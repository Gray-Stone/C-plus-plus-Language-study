#include <iostream>
#include <vector>
#include <cctype>

 using std::vector ;
 using std::cin;
 using std::cout;
 using std::endl;

void Q3_13_a ()
{

	cout << "Q3.13 (a)"<<endl;

	vector<int> a ;

// input a serious of number into the vector a //
 	for (int temp;cin>>temp;)
	{
//		cout << temp <<endl;
		a.push_back(temp);
	}

//	cout << a.size() << endl;

// add each two of them //
	vector<int>::size_type i=1;
	for ( ; i< a.size();i+=2)
	{
		cout << a[i]+a[i-1] <<endl ;
	}
	if ( a.size()%2 ==1 ) cout<< "there is a left over of " << a[i-1]<<endl ;

}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void Q3_13_b ()
{
	cout << "Q3.13 (b)"<<endl;


	vector<int> a ;
// input a serious of number into the vector a //
 	for (int temp;cin>>temp;)
	{
//		cout << temp <<endl;
		a.push_back(temp);
	}

	// add end to top
	vector<int>::size_type i , j ;
	j=a.size()-1;
	i=0;
	for (;i<j;++i,--j)	cout << a[i]+a[j]<<" " ;

	if (i=j) cout<< a[i] <<endl;

}

void Q3_14 ()
{
	cout << " Q3.14 " <<endl ;
	vector<char> c;

// read in a serious of character
	for (char temp;cin>>temp;)
	{
		if ( isalpha(temp) )	c.push_back (temp);
	}

// make every character into uppercase and print
// every eight letter change line
	for (vector<char>::size_type i=0; i<c.size() ; ++i )
	{
		c[i]= toupper(c[i]);
		cout << c[i] ;
		if ( (i+1) %8 ==0 )
		{
			cout<<endl ;
		}
	}

}

 int main ()
 {
 	// page 83
//	Q3_13_a () ;
//	Q3_13_b () ;
	Q3_14 () ;



	return 0;
 }




