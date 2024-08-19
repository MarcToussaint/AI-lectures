---
layout: home
title: AI Lecture Notes and Slides
---

[[Marc Toussaint]](https://www.user.tu-berlin.de/mtoussai/)
[[other teaching material]](https://www.user.tu-berlin.de/mtoussai/teaching/)
[[github sources]](https://github.com/MarcToussaint/AI-lectures)

Welcome to my collection of AI teaching materials. There are two
parts:

* A collection of lecture notes, that are each brief and more blog
  style with commenting. I'm currently adding these one by one. See
  the list below.

* Older traditional AI lectures -- see the [README](https://github.com/MarcToussaint/AI-lectures). This provides latex
  souces and pdfs for lecture slides on traditional AI, Robotics, ML,
  Optimization, and Maths-for-Intelligence-Systems courses.
  
## Lecture Notes

<ul>
{% assign sorted = site.pages | sort: 'date' %}
{% for page in sorted %}
  {% if page.tags == 'note' %}
  <li>
    <a href="{{site.baseurl}}{{page.url}}">{{ page.title }} ({{ page.date | date: '%B %d, %Y' }})</a>
  </li>
  {% endif %}
{% endfor %}
</ul>
