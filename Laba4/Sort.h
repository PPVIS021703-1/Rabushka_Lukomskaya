#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class GnomeSort {
private:
    
	T* arr;   //������ ��� ����������
	int size;  //������ �������

public:
	
    // ��� �������
    GnomeSort(T* a, int n) {
        this->size = n;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = a[i];
        }
    }

    // ��� �������
    GnomeSort(vector<T> a, int n) {
        this->size = n;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = a[i];
        }
    }
   
	// ����������
    void Sort() {
        int index = 1; 

        while (index < size) {
            if (arr[index - 1] < arr[index]) //��� ���������� �� �������� ��������� ���� ��������� �� >=
            {
                index++;
            }
            else
            {
                swap(arr[index - 1], arr[index]);
                index--;
                if (index == 0)
                {
                    index++;
                }

            }
        }
    }

    // ����� �� �����
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};