select name
from instructor;

select distinct dept_name
from instructor;

select dept_name
from instructor;

select ID, name, dept_name, salary*1.1 
from instructor;

select name
from instructor
where salary > 70000 and dept_name = 'Comp. Sci.';

select name, instructor.dept_name, building
from instructor, department 
where instructor.dept_name = department.dept_name;

select *
from instructor, department;

select name, course_id
from instructor, teaches
where instructor.ID = teaches.ID;

select name as instructor_name, course_id
from instructor, teaches
where instructor.ID = teaches.ID and instructor.dept_name = 'Comp. Sci.';

select I.name, T.course_id 
from instructor as I, teaches as T 
where I.id = T.id 

select distinct T.name
from instructor as T, instructor as S
where T.salary > S.salary and S.dept_name = 'Biology';

select dept_name
from department
where building like '%Watson%';

select name
from instructor
where name like 'S%';

select T.*
from instructor as T, teaches as S 
where T.id = S.id 

select *
from instructor
order by salary desc, name asc;

select name
from instructor 
where salary >= 90000 and salary <= 100000;

select name
from instructor 
where salary between 90000 and 100000;


select name, course_id
from instructor as I, teaches as T 
where (I.ID, dept_name) = (T.ID, 'Biology');


(select course_id
from section 
where semester = 'Fall' and year = 2017)
union
(select course_id
from section
where semester = 'Spring' and  year = 2018);

(select course_id
from section 
where semester = 'Fall' and year = 2017)
union all
(select course_id
from section
where semester = 'Spring' and  year = 2018);

(select course_id
from section 
where semester = 'Fall' and year = 2017)
intersect 
(select course_id
from section
where semester = 'Spring' and  year = 2018);

(select course_id
from section 
where semester = 'Fall' and year = 2017)
except 
(select course_id
from section
where semester = 'Spring' and  year = 2018);


select name 
from instructor
where salary is null;

select name
from instructor 
where salary is not null;

select name 
from instructor
where salary > 10000 is unknown;

select avg(salary) as avg_salary 
from instructor 
where dept_name = 'Comp. Sci.';

select count(distinct ID)
from teaches
where semester = 'Spring' and year = '2018';

select dept_name, avg(salary) as avg_salary 
from instructor 
group by dept_name;

/* Find the number of instructor in each department who teach a course in the Spring of 2018 semester */
select dept_name, count(distinct I.ID) as instr_count
from instructor as I, teaches as T
where I.ID = T.ID and T.semester = 'Spring' and T.year = '2018'
group by dept_name; 


select dept_name, avg(salary) as avg_salary
from instructor 
group by dept_name 
having avg(salary) > 42000;

select course_id, avg(tot_cred) as avg_credits
from student, takes
where year = '2017' and student.ID = takes.ID
group by sec_id, semester, year, course_id
having count(student.ID) >= 2; 

select distinct course_id
from section 
where semester = 'Fall' and year = 2017 and
	  course_id in (select course_id
	  				from section 
	  				where semester = 'Spring' and year = 2018);

select distinct course_id
from section 
where semester = 'Fall' and year = 2017 and
	  course_id not in (select course_id
	  				from section 
	  				where semester = 'Spring' and year = 2018);

select distinct name
from instructor 
where name not in ('Mozart', 'Einstein');

select count(distinct ID)
from takes
where (course_id, sec_id, semester, year) in (select course_id, sec_id, semester, year
											  from teaches
											  where teaches.ID = '10101');

/*Find the names of all instructors whose salary is greater than at least one instructor
in the Biology department. */
select distinct name, salary
from instructor
where salary > some(select salary
					from instructor
					where dept_name = 'Biology'
					);


select distinct course_id
from section 
where semester = 'Fall' and year = 2017 and
	  course_id <> some (select course_id
	  				from section 
	  				where semester = 'Spring' and year = 2018);

select distinct name
from instructor
where salary > all (select salary 
					from instructor
					where dept_name = 'Biology');

select dept_name
from instructor 
group by dept_name 
having avg(salary) >= all(select avg(salary)
						  from instructor
						  group by dept_name);

select course_id
from section as S
where semester = 'Fall' and year = 2017 and exists (select *
													from section as T
													where T.semester = 'Spring' and T.year = 2018 
													and S.course_id  = T.course_id );

select S.ID, S.name
from student as S
where not exists ( select course_id
				   from course
				   where dept_name = 'Biology'			   
				   except 
				   select T.course_id
				   from takes as T
				   where S.ID = T.ID);


select count (distinct ID)
from takes
where exists (select course_id, sec_id, semester, year
			  from teaches
			  where teaches.ID = '10101'
			  		and takes.course_id = teaches.course_id 
			  		and takes.sec_id = teaches.sec_id 
			  		and takes.semester = teaches.semester
			  		and takes.year = teaches.year);

/*unique is not yet implemented*/
select T.course_id
from course as T
where  (select R.course_id
			  from section as R
			  where T.course_id = R.course_id and R.year = 2017);

select dept_name, avg_salary
from (select dept_name, avg(salary) as avg_salary 
	  from instructor
	  group by dept_name)
where avg_salary > 42000;	

select max(tot_salary)
from (select dept_name, sum(salary)
	  from instructor
	  group by dept_name) as dept_sum(dept_name, tot_salary);
	
select name, salary, avg_salary 
from instructor I1, lateral(
							select avg(salary) as avg_salary 
							from instructor I2
							where I1.dept_name = I2.dept_name);

with max_budget(value) as
	(select max(budget)
	from department) 
select budget
from department, max_budget 
where department.budget = max_budget.value;

select dept_name, budget
from department
where budget >= all (select max(budget)
					 from department);


select budget
from department, (select max(budget) as max_budget
	  from department) 
where budget = max_budget;


select dept_name,
		(select count(*) 
		from instructor
		where department.dept_name = instructor.dept_name) 
		as num_instructors;
from department

select (select count(*) from teaches) / (select count(*) from instructor)

select dept_name
from instructor
where dept_name <> 'Biology';


select name, course_id
from student natural join takes;

select name, title
from student natural join takes, course
where takes.course_id = course.course_id;

/*Alternatively*/
select name, title
from (student natural join takes) join course using (course_id);

select *
from student join takes on student.ID = takes.ID;
/*Same as*/
select * 
from student, takes
where student.ID = takes.ID;

select *
from student natural left outer join takes;

/*Find all students who have not taken a course*/
select * 
from student natural left outer join takes 
where course_id is null;

select * 
from takes natural right outer join student;

select *
from (select * 
	  from student 
	  where dept_name = 'Comp. Sci.')
	  natural full outer join
	  (select *
	  from takes
	  where semester = 'Spring' and year = 2017);

create view faculty as 
	select ID, name, dept_name
	from instructor;

create view physics_fall_2017 as
	select course.course_id, sec_id, building, room_number
	from course, section
	where course.course_id = section.course_id
		  and course.dept_name = 'Physics'
		  and section.semester = 'Fall'
		  and section.year = 2017;

select course_id
from physics_fall_2017
where building = 'Watson';


create view department_total_salary(dept_name, total_salary) as
	select dept_name, sum(salary)
	from instructor
	group by dept_name;

select * 
from department_total_salary;


create view physics_fall_2017_watson as
	select course_id, room_number
	from physics_fall_2017 
	where building = 'Watson';

select *
from physics_fall_2017_watson;



