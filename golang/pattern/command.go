package pattern

import "fmt"

type Command struct {
	person *person
	method func()
}

func NewCommand(p *Person, method func()) Command {
	return Command{
		person: p,
		method: method,
	}
}

func (c *Command) Execute() {
	c.method()
}

func NewPerson(name string, cmd Command) Person {
	return Person{
		name: name,
		cmd:  cmd,
	}
}

func (p *Person) Buy() {
	fmt.Println("buy")
}

func (p *Person) Cook() {
	fmt.Println("buy")
}
