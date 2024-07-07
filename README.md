Tair Mazriv
209188382
tairmazriv@gmail.com

size:
מחזירה את הסדר גודל המטריצה המייצגת של הגרף

toString:
מחזיר את המטריצה המייצגת של הגרף בתור מחרוזת

operatores:   (בכל המקרים בהם הפונקציה מקבלת שני גרפים, במידה והמטריצות לא אותו סדר גודל תזרק שגיאה

<<  אופרטור פלט - מדפיס עבור גרף את המטריצה המייצגת שלו, כל שורה של המטריצה בתוך [], עם פסיקים בין כל צלע.

(+)             מחזיר חיבור של כל האיברים בשתי המטריצות המייצגות
+=          משנה את המטריצה המייצגת של הגרף לחיבור של שתי המטריצות המייצגות
+(אונרי)  מחזיר את אותו הגרף

(-)             מחזיר חיסור של כל האיברים בשתי המטריצות המייצגות
-=          משנה את המטריצה המייצגת של הגרף לחיסור של שתי המטריצות המייצגות
-(אונרי)  מחזיר את המטריצה המייצגת עם - לפני כל מספר שהוא לא 0

Postfix increment ++  מגדיל את הערך ב1 בכל המקומות במטריצה המייצגת שלא שווים 0, מחזיר את המטריצה המייצגת של הגרף לפני ההוספה
Prefix increment ++    מגדיל את הערך ב1 בכל המקומות במטריצה המייצגת שלא שווים 0, מחזיר את המטריצה המייצגת של הגרף אחרי ההוספה

Postfix decrement --   מקטין את הערך ב1 בכל המקומות במטריצה המייצגת שלא שווים 0, מחזיר את המטריצה המייצגת של הגרף לפני ההורדה
Prefix decrement --     מקטין את הערך ב1 בכל המקומות במטריצה המייצגת שלא שווים 0, מחזיר את המטריצה המייצגת של הגרף אחרי ההורדה

(*)     מחזיר את הכפל מטריצות בין שתי המטריצות המייצגות של הגרפים
*=   מכפיל את כל האיברים במטריצה המייצגת במספר הנתון
/=   מחלק את כל האיברים במטריצה המייצגת במספר הנתון

edges:
מחזירה את ממספר הצלעות בגרף

עוד operators:
==  שני גרפים שווים אם כמות הצלעות וסדר הגודל של המטריצה שלהם שווים
!=  שני גרפים לא שווים אם כמות הצלעות או סדר הגודל של המטריצות שלהם לא שווים
>   אם בגרף אחד יש יותר צלעות מהשני - הוא גדול יותר, אם בשני הגרפים אותה כמות צלעות, הולכים לפי הסדר גודל של המטריצה המייצגת
>=  אם הגרפים מקיימים > או ==
< אותו דבר כמו >
<= אותו דבר כמו >=
