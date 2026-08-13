/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 01:06:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void runAnimalArrayTest() {
	const size_t animalCount = 4;
	Animal *animals[animalCount];
	for (size_t i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();
	for (size_t i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();
	for (size_t i = 0; i < animalCount; i++)
		delete animals[i];
}

void runDeepCopyTest() {
	Dog a1;
	a1.setIdea(0, "idea1");

	std::cout << "a1 idea[0]: " << a1.getIdea(0) << std::endl;
	std::cout << "a1 idea[1]: " << a1.getIdea(1) << std::endl;

	Dog a2;
	a2 = a1;
	a2.setIdea(0, "IDEA1");
	a2.setIdea(1, "IDEA2");

	std::cout << "copied a1 to a2" << std::endl;

	std::cout << "a1 idea[0]: " << a1.getIdea(0) << std::endl;
	std::cout << "a1 idea[1]: " << a1.getIdea(1) << std::endl;
	std::cout << "a2 idea[0]: " << a2.getIdea(0) << std::endl;
	std::cout << "a2 idea[1]: " << a2.getIdea(1) << std::endl;
}

void copyTest() {
	Dog dog;
	dog.setIdea(0, "dog");
	{
		Dog tmp = dog;
		tmp.setIdea(0, "tmp");
		std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
	}
	std::cout << "dog idea[0]: " << dog.getIdea(0) << std::endl;
}

int main() {
	std::cout << "[Copy test]" << std::endl;
	copyTest();

	std::cout << std::endl << "[Animal array test]" << std::endl;
	runAnimalArrayTest();

	std::cout << std::endl << "[Deep copy test]" << std::endl;
	runDeepCopyTest();

	// Animal *animal = new Animal();
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor()
{
  system("leaks -q a.out");
}

#endif
