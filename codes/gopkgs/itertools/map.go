package itertools

func Map[I, O any](arr []I, cb func(v I) O) []O {
	s := make([]O, 0, len(arr))

	for _, v := range arr {
		s = append(s, cb(v))
	}

	return s
}
