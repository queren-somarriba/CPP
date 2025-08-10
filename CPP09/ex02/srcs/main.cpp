/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:30:05 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/27 16:08:01 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
		return (std::cerr << ERROR_USAGE << std::endl, 1);
	try
	{
		timeval start, end;
		std::vector<int> vect = parse_arguments<std::vector<int> >(argc, argv);
		std::cout << "Before: ";
		printNbrLst(vect);
		vect.clear();
		gettimeofday(&start, NULL);
		vect = parse_arguments<std::vector<int> >(argc, argv);
		pairSort<std::vector<int> >(vect);
		mergeSort<std::vector<int> >(vect);
		gettimeofday(&end, NULL);
		double duration = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
		std::cout << "After: ";
		printNbrLst(vect);
		std::cout << "Time to process a range of " << vect.size() << " elements with std::vector<int>: " << duration << " us" << '\n';
		gettimeofday(&start, NULL);
		std::deque<int> dq = parse_arguments<std::deque<int> >(argc, argv);
		pairSort<std::deque<int> >(dq);
		mergeSort<std::deque<int> >(dq);
		gettimeofday(&end, NULL);
		duration = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
		std::cout << "Time to process a range of " << dq.size() << " elements with std::deque<int>: " << duration << " us" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

