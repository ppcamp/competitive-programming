package set

type Set[Key comparable] struct{ set map[Key]bool }

func (s *Set[Key]) Add(key Key)        { s.set[key] = true }
func (s *Set[Key]) Remove(key Key)     { delete(s.set, key) }
func (s *Set[Key]) Exist(key Key) bool { return s.set[key] }
