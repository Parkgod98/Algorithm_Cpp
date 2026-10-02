SELECT member_id,member_name,gender,date_of_birth from MEMBER_PROFILE
where TLNO IS NOT NULL 
and
MONTH(date_of_birth) = 3
and gender = 'W'
order by member_id asc
