/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/28 20:02:24 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename T>
	class	random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
            typedef ft::iterator<ft::random_access_iterator_tag, T>	iterator_type;

			typedef typename iterator_type::iterator_category	iterator_category;
            typedef typename iterator_type::pointer				pointer;
            typedef typename iterator_type::reference			reference;
            typedef typename iterator_type::value_type			value_type;
            typedef typename iterator_type::difference_type		difference_type;
		public:
			random_access_iterator();
			random_access_iterator(pointer ptr);
			random_access_iterator(const random_access_iterator &other);
			random_access_iterator		&operator=(const random_access_iterator &other);
			operator 					random_access_iterator<const T> () const;
			virtual						~random_access_iterator();
		public:
			bool						operator==(const random_access_iterator &other) const;
			bool						operator!=(const random_access_iterator &other) const;
			reference					operator*() const;
			pointer						operator->() const;
			random_access_iterator<T>	&operator++();
			random_access_iterator<T>	operator++(int);
			random_access_iterator<T>	&operator--();
			random_access_iterator<T>	operator--(int);
			reference					operator[](difference_type num) const;
			random_access_iterator<T>	operator+(difference_type num) const;
			random_access_iterator<T>	operator-(difference_type num) const;
			random_access_iterator<T>	&operator+=(difference_type num);
			random_access_iterator<T>	&operator-=(difference_type num);
			difference_type				operator-(const random_access_iterator<T> &other) const;
			bool						operator>(const random_access_iterator<T> &other) const;
			bool						operator<(const random_access_iterator<T> &other) const;
			bool						operator>=(const random_access_iterator<T> &other) const;
			bool						operator<=(const random_access_iterator<T> &other) const;
			pointer						base() const;
		private:
			pointer						_elem;
	};

	/* For constants  */

	template <typename T_L, typename T_R>
	typename random_access_iterator<T_L>::difference_type
	operator-(const random_access_iterator<T_L> &lhs, const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator>(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator<(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator>=(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator<=(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator==(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator!=(const random_access_iterator<T_L> &lhs, \
					const random_access_iterator<T_R> &rhs);

	template <typename T>
	random_access_iterator<T> operator+(typename \
		random_access_iterator<T>::difference_type n, random_access_iterator<T> &rhs);
}

# include "random_access_iterator_impl.tpp"

#endif
