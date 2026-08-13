/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 00:26:39 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//   const Animal* meta = new Animal();
//   const Animal* j = new Dog();
//   const Animal* i = new Cat();

//   std::cout << j->getType() << " " << std::endl;
//   std::cout << i->getType() << " " << std::endl;
//   i->makeSound(); //will output the cat sound!
//   j->makeSound();
//   meta->makeSound();

//   delete meta;
//   delete j;
//   delete i;

//   return 0;
// }

void testNormal() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Dog.getType(): " << j->getType() << std::endl;
	std::cout << "Cat.getType(): " << i->getType() << std::endl;

	std::cout << "Dog.makeSound(): ";
	j->makeSound();

	std::cout << "Cat.makeSound(): ";
	i->makeSound();

	std::cout << "Animal.makeSound(): ";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testWrong() {
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();

	std::cout << "WrongCat.getType(): " << i->getType() << std::endl;

	std::cout << "WrongCat.makeSound(): ";
	i->makeSound();    // WrongCat's makeSound() is not called

	std::cout << "WrongAnimal.makeSound(): ";
	meta->makeSound();

	delete meta;
	delete i;    // WrongCat's destructor is not called
}

int main() {
	std::cout << "[Normal test]" << std::endl;
	testNormal();

	std::cout << std::endl;

	std::cout << "[Wrong test]" << std::endl;
	testWrong();
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor()
{
  system("leaks -q a.out");
}

#endif
