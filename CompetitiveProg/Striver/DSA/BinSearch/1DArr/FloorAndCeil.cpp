#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;

  int temp;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr.push_baack(temp);
  }

  int front{}, back{n-1};
  int mid = (front+back)/2;

  int ans{};

  while (front < back)
  {
    mid = (front+back)/2;
    if (target >= arr[mid] && target < arr[mid+1])
    {
      ans = arr[mid+1]; //ceil
      break;
    }
    else if (target < arr[mid])
    {
      back = mid;
    }
    else if (target > arr[mid])
    {
      front = mid;
    }
  }

  if (arr[mid] == target)
  {
    cout << mid << endl;
  }
  else
  {
    cout << "Not present" << endl;
  }  
  
  return 0;
}
