create table users
(
    id       serial primary key,
    username varchar UNIQUE,
    password varchar,
    email    varchar UNIQUE,
    bio      text,
    image    varchar
);

create table articles
(
    id          serial primary key,
    user_id     varchar,
    slug        varchar UNIQUE,
    title       varchar,
    description text,
    body        text,
    created_at  TIMESTAMP NOT NULL,
    updated_at  TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

create table article_favorites
(
    article_id varchar not null,
    user_id    varchar not null,
    primary key (article_id, user_id)
);

create table follows
(
    user_id   varchar not null,
    follow_id varchar not null
);

create table tags
(
    id   serial primary key,
    name varchar
);

create table article_tags
(
    article_id varchar not null,
    tag_id     varchar not null
);

create table comments
(
    id         serial primary key,
    body       text,
    article_id varchar,
    user_id    varchar,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);