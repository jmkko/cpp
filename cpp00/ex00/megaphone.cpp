/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:43 by jhervoch          #+#    #+#             */
/*   Updated: 2025/03/03 15:51:29 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string sentence;
    int i = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[++i])
            sentence += argv[i];
        for (std::string::iterator it = sentence.begin(); it != sentence.end(); ++it)
            std::cout << static_cast<char>(toupper(*it));
        std::cout << std::endl;
    }
    return 0;
}
