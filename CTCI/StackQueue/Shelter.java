import java.util.LinkedList
import java.util.AbstractQueue

class Shelter{
	AbstractQueue<Animal> dogs = new AbstractQueue<>();
	AbstractQueue<Animal> cats = new AbstractQueue<>();
	LinkedList<Animal> pets = new LinkedList();

	public void enqueue(Animal animal){
		if(animal == DOG)
			dogs.add(animal);
		else
			cats.add(animal);

		pets.add(animal);
	}

	Animal dequeueAny(){
		if(pets.size <= 0) return null;
		if(pets.removeFirst() == DOG)
			return dogs.remove();
		else
			return cats.remove();
	}

	Animal dequeueDog(){
		if(!pets.removeFirstOccurence(DOG)) return null;

		return dogs.remove();
	}

	Animal dequeueCat(){
		if(!pets.removeFirstOccurence(CAT)) return null;

		return cats.remove();
	}
}
