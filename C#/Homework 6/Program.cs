using System;

namespace GameCharacterManagement
{
    public interface ICharacter
    {
        void Attack(ICharacter target);
        void TakeDamage(int damage);
    }

    public abstract class CharacterBase : ICharacter
    {
        public string Name { get; set; }
        public int Health { get; set; }
        public int Defense { get; set; }
        public int AttackPower { get; set; }

        public CharacterBase(string name, int health, int defense, int attackPower)
        {
            Name = name;
            Health = health;
            Defense = defense;
            AttackPower = attackPower;
        }

        public void Attack(ICharacter target)
        {
            Console.WriteLine($"{Name} attacks {((CharacterBase)target).Name}!");
            target.TakeDamage(AttackPower);
        }

        public void TakeDamage(int damage)
        {
            int damageTaken = Math.Max(0, damage - Defense);
            Health -= damageTaken;
            Console.WriteLine($"{Name} takes {damageTaken} damage, remaining health: {Health}");
        }
    }

    public class Archer : CharacterBase
    {
        public Archer(string name) : base(name, 100, 10, 15) { }
    }

    public class Mage : CharacterBase
    {
        public Mage(string name) : base(name, 80, 5, 20) { }
    }

    public class Warrior : CharacterBase
    {
        public Warrior(string name) : base(name, 120, 15, 10) { }
    }

    public static class CharacterFactory
    {
        public static ICharacter CreateCharacter(string type, string name)
        {
            return type.ToLower() switch
            {
                "archer" => new Archer(name),
                "mage" => new Mage(name),
                "warrior" => new Warrior(name),
                _ => throw new ArgumentException("Invalid character type")
            };
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ICharacter archer = CharacterFactory.CreateCharacter("archer", "Robin");
            ICharacter mage = CharacterFactory.CreateCharacter("mage", "Gandalf");
            ICharacter warrior = CharacterFactory.CreateCharacter("warrior", "Conan");

            archer.Attack(mage);
            mage.Attack(warrior);
            warrior.Attack(archer);
        }
    }
}
