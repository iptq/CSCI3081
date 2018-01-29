RESPONDER: Michael Zhang (zhan4854)

AUTHOR: John Eidum (eidum003)

As you reflect on the author's writing, keep in mind the intended audience and purpose of the writing.

AUDIENCE: A programmer joining the project team who has no familiarity with the project.
PURPOSE: Provide sufficient information to this programmer to reduce her/his time and effort to be productive and contributing to the project.
Load index.html and read the mainpage text. Answer these questions corresponding to mainpage, considering that the audience would be a programmer unfamiliar with this project. The go:

1. In the first paragraph of the mainpage, what is the most effective sentence with respect to orienting the reader to the project?

The very first sentence instantly introduces the purpose of the project, and the goal of the game, with details coming in the sentence after.

2. Identify a sentence in the first paragraph that needs to be reworked and state what you think is problematic about that sentence. (Do not edit it.)

The aforementioned first sentence is also a bit problematic. Although I do know it's a game, I'm not really sure about the semantics of the game, since there is some assumption (what is "other robots"?) involved. If I saw this description on a game in the app store I would have a lot of questions before downloading it.

3. Identify a sentence or two in any of the paragraphs that provides the "big picture" with respect to the software, design, or class structure, AND is accompanied by low-level details that help the reader better understand the "big picture."

These two sentences gives a pretty clear introduction to the purpose of the Robots on the screen:

    Robots and SuperBots contain multiple sensors to aid in the automation of their movement and actions. They both contain SensorDistress, SensorEntityType, SensorProximity, and also RobotMotionBehavior, MotionHandlerRobot, and SensorTouch which Player contains.

The first sentence simply states that they have sensors for aiding automation, while the second sentence gives more details on what types of sensors are being used.

4. Comment on the effectiveness of this technique in the example from (3). If it is effective, analyze why you think it works here. If you think there are other details that would be more elucidating, state those.

It's relatively effective without going too deeply into the technical details of each sensor (which would not be appropriate). Only the names of the sensors are listed, but they're named in such a fashion that it's extremely easy to understand what each sensor does without having to understand its implementation. Also, if anyone reading the first sentence was confused at what a sensor could potentially be doing, the second sentence helps the reader understand the "big picture" of the sensors using the examples of the specific sensor types.

5. Identify a topic in the writing that is either underspecified or is discussed too in-depth. If underspecified, what is the most important idea that is missing? If too in-depth, what can be removed?

Nothing is really discussed too in-depth, and nothing is really left out. Overall, I think a better structure would have made it more effective. More about this in the next question.

6. What do you think would be the single most impactful change to this document - in other words, what would you recommend to the author as the one area on which to focus? It could be related to the content (e.g. level of detail, more or less technical information, highlight more or fewer classes, etc.) or to the writing (e.g. reorganize paragraph or sentence order, condense text, improve sentence structure, etc.).

As mentioned in the previous question, I think that the most important improvement that the author could make is to restructure the document better. So far, it looks like it's structured by either class or by whatever order it was in the requirements. However, for this type of document, I think it'd be a lot easier to understand if it followed a structure like

    paragraph 1: game overview and rules
    paragraph 2: overall structure of the project's classes
    
    paragraph 3: semantics of the player
    paragraph 4: "              " robots/superbots
    and so on

7. As a programmer new to this project, which class do you think the document is emphasizing as the place to begin to engage the code? This might be explicit or implicit. What part of the writing made you think you should start with that class?

It definitely points out the file where execution begins, which is main.cc. Personally, I like probing through repositories to try to understand the code so in my opinion this is sufficient, but I understand that some people would like a listing of files/classes and what they do as well.

Now explore the documentation of the classes. Go to the class that you identified in (7).

8. What do you consider to be the best and worst documented method in that class and why. OR, if you think they are all of equal quality, comment on the level of detail provided in the documentation. Is it sufficient, clear, and correct? If it is excellent, state what makes it excellent.

The sensor classes were not really well documented, especially compared to the player or robot classes. The biggest glaring issue was that most of the methods just weren't documented.

9. Skim through all the brief comments on the main classes page. What strikes you as you look at the collection? Is there an effective pattern in the comments? Is there something consistently lacking?

The only thing I'd think was lacking would be the description for the MotionHandler base class. Some parts of the MotionHandlerRobot description should go under MotionHandler too.

Now look at the UML - be conscious of your first reaction!

10. Where did your eye go? What jumps out at you on the page? Is this an important element, thus warrants the attention? If not, offer a suggestion on how to make it less visually prominent.

My eyes were drawn immediately to the SuperBot definition, since it was right in the middle of the page, not to mention it seemed like the center of many connections to other nodes, and it had many fields. While SuperBot is rather important, I think either Robot or Player is more important, especially since SuperBot is just a subclass of Robot.

11. What did the author do in her/his UML diagram that you would like to incorporate into your UML? Why do you like that part of the UML and how does it differ from what you did?

It seemed like it was much more nicely organized. The whole digram is contained in two boxes, while my boxes were just scattered to wherever I could find space.

12. Try to recall your sense of your first attempt to engage the base code, and think of how it is even more complex now. Keeping that in mind, what do you think was the most successful part of the author's writing (in doxygen and UML) with respect to helping a programmer get acclimated to the code? What do you think could be very helpful but needs some rework?

In my opinion, the most helpful part was actually using the names in the mainpage with links going to the actual pages themselves. This means I can just refer back to the main page to see how classes fit in with other classes and then just click the link to go directly to those pages (although a search would also have been equivalently fast). Also, in GraphicsArenaViewer, he provided example code on how to use it which was very nice.

