/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:01:50 by mafzal            #+#    #+#             */
/*   Updated: 2026/06/15 20:05:07 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		for (size_t j = 0; j < str.size(); j++)
			str[j] = std::toupper((str[j]));
		std::cout << str;
		if (i + 1 < argc)
			std::cout << " ";
	}
	std::cout << "\n";
	return (0);
}
