import java.util.LinkedList;
import java.util.Scanner;

public class Shelter{
	Queue dogs = new Queue();
	Queue cats = new Queue();
	LinkedList<Animal> pets = new LinkedList<Animal>();

	public void enqueue(Animal animal){
		if(animal == Animal.DOG)
			dogs.enqueue(animal);
		else
			cats.enqueue(animal);

		pets.add(animal);
	}

	Animal dequeueAny(){
		if(pets.size() <= 0) return null;
		if(pets.removeFirst() == Animal.DOG)
			return (Animal) dogs.dequeue();
		else
			return (Animal) cats.dequeue();
	}

	Animal dequeueDog(){
		if(!pets.removeFirstOccurrence(Animal.DOG)) return null;

		return (Animal) dogs.dequeue();
	}

	Animal dequeueCat(){
		if(!pets.removeFirstOccurrence(Animal.CAT)) return null;

		return (Animal) cats.dequeue();
	}

	public static void main(String[] args){
		Shelter shelter = new Shelter();
		
		Scanner input = new Scanner(System.in);

		while(true){
			System.out.printf("Enter 'd', 'c', or 'q': ");

			String comm = input.nextLine();

			if(comm.equals("d"))
				shelter.enqueue(Animal.DOG);
			else if(comm.equals("c"))
				shelter.enqueue(Animal.CAT);
			else
				break;

		}

		while(true){
			System.out.printf("Dequeue 'a' 'd', 'c', or 'q': ");

			String comm = input.nextLine();

			if(comm.equals("a"))
				System.out.println("Got a " + shelter.dequeueAny() );

			else if(comm.equals("d"))
				System.out.println("Got a " + shelter.dequeueDog() );
			else if(comm.equals("c"))
				System.out.println("Got a " + shelter.dequeueCat() );

			else break;

		}

		System.out.println("Program End");

	}
}

class Queue{
	Node first, last;

	void enqueue(Object item){
		if(first == null){
			last = new Node(item);
			first = last;
		} else {
			last.next = new Node(item);
			last = last.next;
		}

	}

	Object dequeue(){
		if(first != null){
			Object item = first.data;
			first = first.next;
			if(first == null) last = null;
			return item;
		}

		return null;

	}
}

class Node{
	Node next = null;
	Object data;

	public Node(Object data){
		this.data = data;
	}
}

enum Animal{ DOG, CAT; }
