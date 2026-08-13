/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:13 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/11 13:19:57 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook {
	private:
		static const int MAX_CONTACT = 8;
		static const int COLUMN_WIDTH = 10;
		int currentIndex;
		Contact contacts[MAX_CONTACT];

	private:
		static std::string truncateAndAppendEllipsis(std::string str);
		std::string getUserInputAsString(std::string prompt);
		int getCurrentIndex();
		void addContact(Contact contact);
		void printContactInfo(const Contact& contact) const;
		void printHeader();
		void printSearchListRow(const Contact& contact, const int) const;
		void printSearchList();
		void printContactAtIndex(int i);

	public:
		void initCurrentIndex();
		void search();
		void add();
};

#endif
