#include <iostream>
#include "Statistic.h"

using namespace std;

int main(int argc, char* argv[])
{
	Statistic::Add(1, ST_TYPE_PKT_DROP);

	cout<<Statistic::GetCount(ST_TYPE_PKT_DROP)<<endl;
	return 0;
}
