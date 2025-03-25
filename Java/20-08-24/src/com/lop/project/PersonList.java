package com.lop.project;

import java.util.ArrayList;

class PersonList {
    ArrayList<Person> persons;

    PersonList() {
        persons = new ArrayList<>();
    }

    void addPerson(Person person) {
        persons.add(person);
    }

    void removePerson(String name) {
        persons.removeIf(person -> person.name.equals(name));
    }

    Person findPerson(String name) {
        for (Person person : persons) {
            if (person.name.equals(name)) {
                return person;
            }
        }
        return null;
    }
}
