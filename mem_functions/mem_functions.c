#define _CRT_SECURE_NO_WARNINGS
                                         // memcpy - void * memcpy ( void * destination, const void * source, size_t num )
                               //�ڴ濽��
int main()
{
    int arr1[] = { 1,2,3,4,5,6,7,8,8 };
    int arr2[20];
    memcpy(arr2, arr1, sizeof(arr1));
    return 0;
}

//ģ��ʵ��memcpy
#include <assert.h>
#include <string.h>
void* my_memcpy(void* dest, const void* sourse, size_t num)
{
    assert(dest && sourse);
    void* tep = dest;
    while (num--)
    {
        *(char*)dest = *(char*)sourse;
        sourse = (char*)sourse + 1;
        dest = (char*)dest + 1;
    }
    return tep;
}
int main()
{
    int arr1[] = { 1,2,3,4,5,6,7,8,8 };
    int arr2[20];
    my_memcpy(arr2, arr1, sizeof(arr1));
    int arr3[] = { 1,2,3,4,5,6,7,8,9 ,10};
    my_memcpy(arr3+2, arr3, 20);  
    //ϣ��������� arr3 = {1,2,1,2,3,4,5,8,9,10}    ����memcpyֻ���𿽱���������ռ��е�����  �ֵ�����VS�༭����memcpy��ʵ��memmove����
    //�ص��ڴ�Ŀ���Ӧ���õ� memmove����
    return 0;
}


                                      // memmove - void * memmove ( void * destination, const void * source, size_t num )
                              // �ص��ڴ�֮������ݿ���
int main()
{
    int arr3[] = { 1,2,3,4,5,6,7,8,9 ,10};
    memmove(arr3+2, arr3, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr3[i]);   //��ӡ��1 2 1 2 3 4 5 8 9 10
    }
    return 0;
}




//ģ��ʵ��memmove
#include <assert.h>
void* my_memmove(void* dest, const void* sourse, size_t num)
{
    assert(dest && sourse);
    void* tmp = dest;
    if (dest < sourse)   //��ǰ���
    {
        while (num--)
        {
            *(char*)dest = *(char*)sourse;
            dest = (char*)dest + 1;
            sourse = (char*)sourse + 1;
        }
    }
    else                 //�Ӻ���ǰ��
    {
        while (num--)
        {
            *((char*)dest+num) = *((char*)sourse + num);
        }
    }
    return tmp;
}
int main()
{
    int arr3[] = { 1,2,3,4,5,6,7,8,9 ,10 };
    my_memmove(arr3 + 2, arr3, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr3[i]);   //��ӡ��1 2 1 2 3 4 5 8 9 10
    }
    return 0;
}


                        // memcmp - int memcmp ( const void * ptr1, const void * ptr2, size_t num )
                //�ڴ�Ƚ�
int main()
{
    int arr1[] = { 1,2,3,4,5}; // 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
    int arr2[] = { 1,3,2};     // 01 00 00 00 03 00 00 00 02 00 00 00
    int ret = memcmp(arr1, arr2, 12);    //arr1<arr2
    printf("%d", ret); //С��0������
    return 0;
}


                              //memset - void * memset ( void * ptr, int value, size_t num )
                     //�ڴ�����  �Ὣÿ���ֽڶ���Ϊvalue
int main()
{
    char arr1[] = "hello world";
    char arr2[] = "hello world";
    memset(arr1, 'x', 5);      // 5���ֽ�
    printf("%s\n", arr1);
    memset(arr2 + 6, 'x', 5);
    printf("%s\n", arr2);
    return 0;
}