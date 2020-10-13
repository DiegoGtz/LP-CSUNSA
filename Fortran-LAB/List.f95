module linked_list
    implicit none
    type list_node
        integer :: id
        character(len = 8) :: firstname
        !character(len = 20) :: msn 
        type (list_node), pointer :: next => null()
        type (list_node), pointer :: previous => null()
    end type list_node

    type list_pointer
        integer :: isNegative
        type (list_node), pointer :: head => null()
        type (list_node), pointer :: tail => null()
    end type list_pointer

    contains

    subroutine printList(list)
        type (list_pointer), target :: list
        type (list_node), pointer :: current

        if(list%isNegative == 1) then
            write(*,fmt="(a)", advance="no") "-"
        end if
        current => list%head
        do while (associated(current))
           ! write(*,fmt="(i1)", advance="no") current%id
           
   		   print *, current%id, current%firstname

           current => current%next
        end do
        write(*,*)
    end subroutine printList

    subroutine SearchL(list,date)
        type (list_pointer), target :: list
        type (list_node), pointer :: temp 

        integer date

        temp => list%head

        do while(associated(temp))

        	if (temp%id == date) then
				write(*,*)"Encontrado"
				return
			else
        		
        		temp=>temp%next
        	end if
        end do
        write(*,*)"No encontrado" 
		 
        
    end subroutine SearchL

    subroutine EditList(list, old_date, newName)
    	type(list_pointer), target :: list
    	type(list_node),  pointer :: temp
    	character(len=8) :: newName

    	integer :: old_date
    	integer :: new_date

        temp => list%head

        do while (associated(temp))
        	if (temp%id == old_date) then
        		write(*,*) "Dato encontrado, actualizando ... "

        		temp%firstname = newName

        		return
        	else 
        		temp=>temp%next
        	end if
        end do 
        
    end subroutine EditList


    subroutine insertBack(list, id, firts_name)
        type (list_pointer), target :: list
        type (list_node), pointer :: node
        Character(*) :: firts_name
     
        integer id
        integer :: number

        !if(str == "-") then
          !  list%isNegative = 1
         !   return
        !end if
        ! Convert the read in character to an integer, and then assign it the node
        !read(str, "(i1)") idber
        number = id
        allocate(node)
        node%id = number
        node%firstname = firts_name
        
        if(.not. associated(list%head)) then
            list%head => node
        else
            node%previous => list%tail
            list%tail%next => node
        end if
        list%tail => node
    end subroutine insertBack

    subroutine insertFront(list, number)
        type (list_pointer), target :: list
        type (list_node), pointer :: node
        integer :: number
        allocate(node)
        node%id = number

        if(.not. associated(list%head)) then
            list%tail => node
        else
            list%head%previous => node
            node%next => list%head
        end if
        list%head => node
    end subroutine insertFront
    
    subroutine freeList(list)
        type (list_pointer), pointer :: list
        type (list_node), pointer :: curr
        type (list_node), pointer :: delete

        curr => list%head

        do while(associated(curr))
            delete => curr
            curr => curr%next
            deallocate(delete)
        end do

        deallocate(list)
    end subroutine freeList
end module linked_list


program main

    use linked_list
    implicit none
    type (list_pointer), pointer :: listOne

    integer number, date1, date2

    character(len=8) :: date3

    allocate(listOne)

    call insertBack(listOne,1,'Diego')
    call insertBack(listOne,2,"Juan")
    call insertBack(listOne,3,"Alex")

    !call printList(listOne)

    call insertBack(listOne,4,"Pedro")
    call insertBack(listOne,5,"Martin")  
    call printList(listOne)

    write(*,*) "**********************************************"
    write(*,*) "Busqueda"
    write(*,*) "Ingrese el id que desea buscar : "
    read (*,*) number 

    call SearchL(listOne,number)  


    write(*,*) "**********************************************"
    write(*,*) "Actulizar datos"
    write(*,*) "Lista Incial"
    call printList(listOne)
    Write(*,*) "ID a actualizar : "
    read(*,*) date1
    write(*,*)"Nuevo dato : "
    read(*,*) date3
    call EditList(listOne, date1, date3)

    write(*,*) "Nueva lista actualizada "

    call printList(listOne)

    
end program main