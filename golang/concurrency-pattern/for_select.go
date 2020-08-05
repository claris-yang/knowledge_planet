package pattern

func for_select1() {

	done := make(chan int, 0)
	for {
		select {
		case <-done:
			return
		default:
		}
	}
}

func for_select2() {
	done := make(chan int, 0)
	stringStream := make(chan string)
	for _, s := range []string{"a", "b", "c"} {
		select {
		case <-done:
			return
		case stringStream <- s:
		}
	}
}

var or func(channels ...<-chan interface{}) <-chan interface{}

func Select2() {
	or = func(channels ...<-chan interface{}) <-chan interface{} {
		switch len(channels) {
		case 0:
			return nil
		case 1:
			return channels[0]
		}

		orDone := make(chan interface{})
		go func() {
			defer close(orDone)
		}

	}
}
