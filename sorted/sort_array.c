/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:58 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:49:00 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	swap(int *a, int *b)
{
	int	help;

	help = *a;
	*a = *b;
	*b = help;
}

static int	pivot_index(int *arr, int begin, int end)
{
	int	k;

	k = begin + 1;
	while (k <= end)
	{
		if (arr[begin] < arr[k])
			return (k);
		if (arr[begin] > arr[k])
			return (begin);
		k++;
	}
	return (-1);
}

static int	create_partition(int *arr, int begin, int end, int pivot)
{
	while (arr[begin] < pivot)
		begin++;
	while (arr[end] >= pivot)
		end--;
	if (begin < end)
		swap(&arr[begin], &arr[end]);
	while (begin < end)
	{
		while (arr[begin] < pivot)
			begin++;
		while (arr[end] >= pivot)
			end--;
		if (begin < end)
			swap(&arr[begin], &arr[end]);
	}
	return (begin);
}

void	sort_array(int *arr, int begin, int end)
{
	int	pivot;
	int	partition;

	pivot = pivot_index(arr, begin, end);
	if (pivot == -1)
		return ;
	partition = create_partition(arr, begin, end, arr[pivot]);
	sort_array(arr, begin, partition - 1);
	sort_array(arr, partition, end);
}
