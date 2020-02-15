/*
** This program reads input lines from the standard input and prints
** each input line, followed by just some portions of the lines, to
** the standard output.
**
** The first input is a list of column numbers, which ends with a
** negative number.  The column numbers are paired and specify
** ranges of columns from the input line that are to be printed.
** For example, 0 3 10 12 -1 indicates that only columns 0 through 3
** and columns 10 through 12 will be printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	MAX_COLS	20	/* max # of columns to process */
#define	MAX_INPUT	1000	/* max len of input & output lines */

// 函数原型，参数名字并非必须
int	read_column_numbers( int columns[], int max );
void rearrange( char *output, char const *input,
	    int n_columns, int const columns[] );

int main( void )
{
	int	n_columns;		        /* # of columns to process */
	int	columns[MAX_COLS];	    /* the columns to process */
	char input[MAX_INPUT];    	/* array for input line */
	char output[MAX_INPUT];	    /* array for output line */

	/*
	** Read the list of column numbers
	*/
	n_columns = read_column_numbers( columns, MAX_COLS );

    printf("please input string...\n");

	/*
	** Read, process and print the remaining lines of input.
	** gets函数从标准输入读取一行文本，并保存到作为参数传递给他的数组中
	** 返回非NULL表示读取成功
	*/
	while( gets( input ) != NULL ){
		printf( "Original input : %s\n", input );
		rearrange( output, input, n_columns, columns );
		printf( "Rearranged line: %s\n", output );
	}

	return EXIT_SUCCESS;
}

/*
** Read the list of column numbers, ignoring any beyond the specified
** maximum.
** C语言中，没有获取数组长度的方法，因此数组长度需要自行传入
*/
int read_column_numbers( int columns[], int max )
{
	int	num = 0;
	int	ch;

    printf("please input column...\n");

	/*
	** Get the numbers, stopping at eof or when a number is < 0.
	** scanf函数的返回值是成功转换并存储在参数中的值的个数
	*/
	while( num < max && scanf( "%d", &columns[num] ) == 1
	    && columns[num] >= 0 ) {
        num += 1;
	}

	/*
	** Make sure we have an even number of inputs, as they are
	** supposed to be paired.
	*/
	// if( num % 2 != 0 ){
	// 	// puts就是输出并换行
	// 	puts( "Last column number is not paired." );
	// 	exit( EXIT_FAILURE );
	// }

	/*
	** Discard the rest of the line that contained the final
	** number.
	** getchar函数从标准输入读取一个字符，并返回他的值，如果不存在任何字符则返回EOF，用于提示文件的结尾
	** EOF是个整形，比字符类型要长
	*/
	while( (ch = getchar()) != EOF && ch != '\n' )
	// 分号独占一行，防止误以为后续代码也是while循环的一部分
		;

	return num;
}

/*
** Process a line of input by concatenating the characters from
** the indicated columns.  The output line is then NUL terminated.
** n_columns 列数量的长度
** columns   列数组
*/
void rearrange( char *output, char const *input,
    int n_columns, int const columns[] )
{
	int	output_col;	/* 输出的字符串长度累计 */
	int	len;		/* 输入字符串的长度 */

    // 计算输入字符串的长度
	len = strlen( input );
	output_col = 0;

	/*
	** Process each pair of column numbers.
	*/
	for(int col = 0; col < n_columns; col += 2 ){
		/*
		** If the input line isn't this long or the output
		** array is full, we're done.
		** 判断当前列长度是否大于输入字符串长度
		*/
		if( columns[col] >= len ||
		    output_col == MAX_INPUT - 1 ) {
			continue;
		}

		int	nchars;
		if( col + 1 < n_columns )
		    nchars = columns[col + 1] - columns[col] + 1;
		else
		    nchars = len - columns[col + 1];
	
		/*
		** If there isn't room in the output array, only copy
		** what will fit.
		** 最后一位是 '\0' 预留位
		*/
		if( output_col + nchars > MAX_INPUT - 1 ) {
			nchars = MAX_INPUT - output_col - 1;
		}

		/*
		** Copy the relevant data.
		** 从 input + columns[col] 地址开始，拷贝 nchars 个字符到 output + output_col位置
		*/
		strncpy( output + output_col, input + columns[col],
		    nchars );
		output_col += nchars;
	}
	// 字符串结束位置
	output[output_col] = '\0';
}
