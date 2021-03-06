/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:31 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/22 16:11:40 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ispunct(int c)
{
	return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126));
}
